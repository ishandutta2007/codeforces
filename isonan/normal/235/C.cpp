#include <cstdio>
#include <cstring>
#include <set>

std::set<int>set;
int son[2000001][26],fa[2000001],size[2000001],len[2000001],cnt=1,last=1,pre[2000001][22],n,Q,tax[2000001],pos[2000001],P=998244353;
long long hash[2000001];
char str[2000001];
void add(int x){
    int p=last;
    size[last=++cnt]=1;
    len[last]=n;
    for(;p&&!son[p][x];p=fa[p])son[p][x]=last;
    if(!p)return (void)(fa[last]=1);
    int q=son[p][x];
    if(len[q]==len[p]+1)return (void)(fa[last]=q);
    len[++cnt]=len[p]+1;
    fa[cnt]=fa[q];
    fa[q]=fa[last]=cnt;
    for(int i=0;i<26;i++)son[cnt][i]=son[q][i];
    for(;son[p][x]==q;p=fa[p])son[p][x]=cnt;
}
int min(int a,int b){return a<b?a:b;}
bool allsame(){
    for(int i=2;i<=n;i++)if(str[i]!=str[i-1])return 0;
    return 1;
}
typedef long long ll;
int qsm(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=(ll)ans*a%P;
        a=(ll)a*a%P;
        b>>=1;
    }
    return ans;
}
int main(){
    scanf("%s",str+1);
    for(n=1;str[n];n++)add(str[n]-'a');
    
    for(int i=1;i<=cnt;i++)tax[len[i]]++;
    for(int i=1;i<=n;i++)tax[i]+=tax[i-1];
    for(int i=cnt;i;i--)pos[tax[len[i]]--]=i;
    for(int i=cnt;i;i--)size[fa[pos[i]]]+=size[pos[i]];
    
    for(int i=1;i<=cnt;i++)pre[i][0]=fa[i];
    for(int j=1;j<=21;j++)
        for(int i=1;i<=cnt;i++)
            pre[i][j]=pre[pre[i][j-1]][j-1];
            
//	for(int i=1;i<=cnt;i++){
//		printf("%d : %d : -> %d : ",i,len[i],fa[i]);
//		for(int j=0;j<26;j++)if(son[i][j])printf("(%c %d)",j+'a',son[i][j]);
//		putchar('\n');
//	}
    
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++){
        scanf("%s",str+1);
        n=strlen(str+1);
        for(int i=1;i<=n;i++)str[i+n]=str[i];
        int p=1,length=0,pow=qsm(6666,n);
        long long ans=0;
        for(int i=1;i<n<<1;i++){
            hash[i]=((ll)hash[i-1]*6666+(ll)233*str[i])%P;
            if(i>n){
                if(i==n+1)hash[i]=(hash[i]-((ll)pow*hash[i-n]%P)+P)%P;
                else hash[i]=(hash[i]-((ll)pow*233*str[i-n]%P)+P)%P;
            }
            while(p&&!son[p][str[i]-'a'])p=fa[p];
            if(!p)p=1,length=0;
            else length=min(length,len[p])+1,p=son[p][str[i]-'a'];
            //printf("%d %d %d\n",i,p,length);
            if(i<n||set.count(hash[i]))continue;
            set.insert(hash[i]);
            int now=p;
            for(int j=21;~j;j--)if(len[pre[now][j]]>=n)now=pre[now][j];
            if(length>=n)ans+=size[now];
        }
        set.clear();
        printf("%I64d\n",ans);
    }
}