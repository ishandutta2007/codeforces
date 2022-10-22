#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=N*400,mod=1e9+7;
int n;
char a[N];
int l[N],r[N];
vector<int>v[N];
int c[N];
int s[N];
int main()
{
    cin>>n;
    scanf("%s",a+1);
    for(int i=0;i<26;i++)c[i]=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++){
            if(c[j]<=a[i]-'a'){
                s[i]=j;
                ans=max(ans,j);
                c[j]=a[i]-'a';
                break;
            }
        }
    }

    cout<<ans+1<<endl;
    for(int i=1;i<=n;i++){
        printf("%d ",s[i]+1);
    }
    return 0;
}
/*
*/