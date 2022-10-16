#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define m ((l+r)/2)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k,a;cin>>n>>k;
    bool poss[n+5];
    cout<<"? "<<n<<endl;
    cin>>k;
    int cnt=1;
    int ls=1;
    cout<<"? "<<n<<endl;
    cin>>a;
    if(a!=k){
        if(a<k)cout<<"! 1"<<endl;
        else cout<<"! "<<n-1<<endl;
        return 0;
    }
    cout<<"? 1"<<endl;
    cin>>a;
    if(a!=k){
        cout<<"? "<<n<<endl;
        cin>>a;
        if(a==k){
            if(n%2==0){
                cout<<"? 1"<<endl;
                cin>>a;
                if(a>k){
                    cout<<"! "<<n<<endl;
                    return 0;
                }
            }
        }
    }
    while(a==k){
        cnt++;
        cout<<"? "<<ls<<endl;
        cin>>a;
        if(a==k)ls+=cnt-1;
    }
    int l=ls,r=min(ls+cnt+cnt,n);
    while(l!=r){
        cout<<"? "<<m<<endl;
        cin>>a;
        if(a>k)r=m;
        else if(a<k)l=m+1;
        else if(a==k){
            l=m;break;
        }
    }
    if(n%2==0){
        cout<<"? "<<(l+1)%n<<endl;
        cin>>a;
        if(a<k)l=(l+n/2)%n;
    }
    cout<<"! "<<l<<endl;
    return 0;
}