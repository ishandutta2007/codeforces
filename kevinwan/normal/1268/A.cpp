#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    string s;
    cin>>s;
    int add=0;
    for(int i=k;i<n;i++){
        if(s[i]<s[i%k])break;
        else if(s[i]>s[i%k]){
            add=1;break;
        }
    }
    s[k-1]+=add;
    for(int i=k-1;i>=0;i--){
        if(s[i]>'9')s[i]-=10,s[i-1]++;
    }
    for(int i=k;i<n;i++)s[i]=s[i%k];
    cout<<n<<'\n'<<s;
}