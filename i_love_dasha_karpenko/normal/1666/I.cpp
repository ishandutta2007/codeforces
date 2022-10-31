#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(vec) vec.begin(),vec.end()
//#define endl '\n'
vector< pair< pair<int,int> ,pair<int,int> > > ans;
const int N = 207;
int ask(int x,int y){
    cout<<"SCAN "<<x<<' '<<y<<endl;
    int ans; cin>>ans;
    return ans;
}
int n,m;
int dig(int x,int y){

    if (x<1 || x>n || y<1 || y>m)
        return 0;
    cout<<"DIG "<<x<<' '<<y<<endl;
    int ret;
    cin>>ret;
    return ret;
}
void solve(){

    cin>>n>>m;
    int d1 = ask(1,1),d2 = ask(1,m);
    int sx = (d1+d2+6-2*m)/2;
    int sy = d1-sx+4;
    int midx = (sx+1)/2,midy = (sy+1)/2;
    int d3 = ask(midx,midy);
    int d4 = ask(midx,m);
    int y1 = (d3-d4+2*m)/2;
    int y2 = sy-y1;
    int dx = d3-max(y1,y2)+min(y1,y2);
    int x1 = (sx+dx)/2;
    int x2 = sx-x1;
    if (dig(x1,y1)){
        dig(x2,y2);
    }
    else{
        dig(x1,y2); dig(x2,y1);
    }
}

int main() {

    //ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}