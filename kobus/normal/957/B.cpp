
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
#define MAXN 512345
#define INF LLONG_MAX/2
#define MOD 1000000007
#define cte 10002
#define MAX LLONG_MAX

char m[51][51];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(4);
    cout.setf(ios::fixed);

    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)cin>>m[i][j];
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]=='#'){
                for(int i2=0;i2<r;i2++){
                    if(m[i2][j]=='#'){
                        for(int j2=0;j2<c;j2++){
                            if(m[i2][j2]=='#'){
                                if(m[i][j2]=='.'){
                                    cout<<"No"<<endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout<<"Yes"<<endl;


    
    return 0;
}