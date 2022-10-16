#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,x,y;
    cin>>n>>q;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        int ad=0;
        if((x+y)%2==1)ad+=((n*n/2)+(n%2));
        else ad+=((x-1)*n)%2;
        //cout<<ad<<endl;
        ad+=(((x-1)*n)/2);
        //cout<<ad<<endl;
        ad+=(y/2+y%2);
        cout<<ad<<endl;
    }
    return 0;
}