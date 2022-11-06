#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uhoh(i) {printf("%d",i);return 0;}
ll n,k,s,f=1,c;
void walk(ll v){//cout<<"walk "<<v<<" ";
    c+=f*v;
    cout<<c+1<<" ";
    f*=-1;
}
int main(){
    cin>>n>>k>>s,--n;
    if(s<k||n*k<s)cout<<"NO";
    else{
        cout<<"YES\n";
        for(int i=0;i<s%k;i++)walk(s/k+1);
        for(int i=s%k;i<k;i++)walk(s/k);
    }
    return 0;
}