#include<bits/stdc++.h>
#define LL long long
#define PB push_back
#define PII pair<int,int>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e6+10,M=N*400,mod=1e9+7;
int n;
char a[N];
int s[N];
int main()
{
    cin>>n;
    scanf("%s",a+1);
    s[1]=0;
    for(int i=2;i<=n;i++){
        s[i]=-1;
        for(int j=1;j<i;j++){
            if(a[j]>a[i]){
                if(s[i]==s[j]){
                    cout<<"NO"<<endl;
                    return 0;
                }
                s[i]=!s[j];
            }
        }
        if(s[i]==-1)s[i]=0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)printf("%d",s[i]);
    return 0;
}
/*
*/