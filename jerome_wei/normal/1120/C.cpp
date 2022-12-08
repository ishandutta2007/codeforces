#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,SZ=26;

struct SuffixAutomaton
{
	struct NODE{
		int ch[SZ],fa;int len,right,left;
	}t[N];
	int root,last,cnt;
	inline int newnode(int _len){
		t[++cnt].len=_len;
		t[cnt].left=N;
		return cnt;
	}
	inline void init(){//"
		root=last=newnode(0);
	}
	inline void ins(int id,int c)//"c=(char)-'a';
    {
        int nq=newnode(t[last].len+1),q=last;
        for(;q&&!t[q].ch[c];q=t[q].fa)t[q].ch[c]=nq;
        if(q==0) t[nq].fa=root;
        else if(t[t[q].ch[c]].len==t[q].len+1)t[nq].fa=t[q].ch[c];
        else{
            int np=newnode(t[q].len+1),p=t[q].ch[c];
            memcpy(t[np].ch,t[p].ch,sizeof(t[p].ch));
            t[np].fa=t[p].fa;
            t[p].fa=t[nq].fa=np;
            for(;q&&t[q].ch[c]==p;q=t[q].fa)t[q].ch[c]=np;
        }
        t[nq].right=1,t[nq].left=id,last=nq;
    }
    int topo[N],buc[N];
    inline void toposet(){
        int mx=0;
        for(int i=1;i<=cnt;i++)buc[t[i].len]++,mx=max(mx,t[i].len);
        for(int i=1;i<=mx;i++)buc[i]+=buc[i-1];
        for(int i=1;i<=cnt;i++)topo[buc[t[i].len]--]=i;
    }
    inline void cal_right(){
        toposet();
        for(int i=cnt;i;i--){
            int cur=topo[i];
            t[t[cur].fa].right+=t[cur].right;
            t[t[cur].fa].left=min(t[cur].left, t[t[cur].fa].left);
        }
    }
}SAM;
char str[N];
int f[N];
int n,a,b;
int main()
{
	cin>>n>>a>>b;
    SAM.init();
    scanf("%s",str+1);
    int len=strlen(str+1);
    for(int i=1;i<=len;i++)SAM.ins(i,str[i]-'a');
    SAM.cal_right();
    int id=SAM.root;
    for(int i=1;i<=n;i++)f[i]=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		id=SAM.t[id].ch[str[i]-'a'];
		int cur=id;
		f[i]=f[i-1]+a;
		for(int len=i;len;len--){
			while(SAM.t[SAM.t[cur].fa].len>=len){
				cur=SAM.t[cur].fa;
				if(SAM.t[cur].left <= i-len){
					f[i]=min(f[i-len]+b,f[i]);
				}
			}
		}
	}
	cout<<f[n]<<endl;
}