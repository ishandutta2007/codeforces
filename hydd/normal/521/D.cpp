#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long double,int> pdi;
int k,n,m,a[210000],op[210000],Ans[210000];
vector<pii> vec[210000][4];
vector<pdi> ans;
char Getchar(){
    static char now[1<<20],*S,*T;
    if (T==S){
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}
int read(){
    int x=0,f=1;
    char ch=Getchar();
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1;
        ch=Getchar();
    }
    while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
    return x*f;
}
inline bool cmp(int a,int b){
	return op[a]<op[b]||(op[a]==op[b]&&a<b);
}
int main(){
	k=read(); n=read(); m=read();
	for (int i=1;i<=k;i++) a[i]=read();
	int pos,x;
	for (int i=1;i<=n;i++){
		op[i]=read(); pos=read(); x=read();
		vec[pos][op[i]-1].push_back(pii(x,i));
	}
	for (int i=1;i<=k;i++){
		if (!vec[i][0].empty()){
			sort(vec[i][0].begin(),vec[i][0].end(),greater<pii>());
			pii tmp=vec[i][0][0];
			if (tmp.first>=a[i]) vec[i][1].push_back(pii(tmp.first-a[i],tmp.second));
		}
		if (!vec[i][1].empty()){
			sort(vec[i][1].begin(),vec[i][1].end(),greater<pii>());
			ll now=a[i];
			for (int j=0;j<(int)vec[i][1].size();j++){
				pii tmp=vec[i][1][j];
				ans.push_back(pdi((long double)(now+tmp.first)/now,tmp.second));
				now+=tmp.first;
			}
		}
		if (!vec[i][2].empty()){
			sort(vec[i][2].begin(),vec[i][2].end(),greater<pii>());
			for (int j=0;j<(int)vec[i][2].size();j++){
				pii tmp=vec[i][2][j];
				ans.push_back(pdi(tmp.first,tmp.second));
			}
		}
	}
	sort(ans.begin(),ans.end(),greater<pdi>());
	int cnt=0;
	for (int i=0;i<(int)ans.size()&&i<m;i++) Ans[++cnt]=ans[i].second;
	sort(Ans+1,Ans+cnt+1,cmp);
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++) printf("%d ",Ans[i]);
	return 0;
}