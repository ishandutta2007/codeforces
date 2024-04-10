#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int,int>
#define PB push_back
#define POP pop_back
#define FI first
#define SE second
#define endl '\n'
#define ls x<<1
#define rs x<<1|1
const int N=3e6+7,mod=1e9+7,INF=1e9;
int n,m,x,y;
char a[N],b[N];
char s[N],ss[N];
int main()
{
    int cnt=0;
    cin>>n;
    scanf("%s",a+1);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1]&&cnt%2==0){
            continue;
        }
        else{
            b[cnt++]=a[i];
        }
    }
    if(cnt&1)cnt--;
    cout<<n-cnt<<endl;
    for(int i=0;i<cnt;i++){
        printf("%c",b[i]);
    }cout<<endl;
    return 0;
}