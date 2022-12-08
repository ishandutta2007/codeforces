#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000007
#define p 41
#define LOGMAXN 20


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(1);
    cout.setf(ios::fixed);

    int r,c;
    cin>>r>>c;
    int comh=INF,fimh=-INF,comv=INF,fimv=-INF;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char ch;
            cin>>ch;
            if(ch=='B'){
                //cout<<i<<" "<<j<<endl;
                comh=min(comh,j);
                fimh=max(fimh,j);
                comv=min(comv,i);
                fimv=max(fimv,i);
            }
        }
    }
    //cout<<comh<<" "<<fimh<<" "<<comv<<" "<<fimv<<endl;
    cout<<((comv+fimv)/2)+1<<" "<<((comh+fimh)/2)+1<<endl;


    return 0;
}