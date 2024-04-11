#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 2123456
#define INF numeric_limits<ll>::max()
#define MOD 1000000007

int vx[8]={0,0,0,1,1,2,2,2};
int vy[8]={0,1,2,0,2,0,1,2};

char m[1123][1123];
bool d[1123][1123];


int l,c;

bool isval(int i, int j){
    return i>=0&&j>=0&&i<l&&j<c&&m[i][j]=='#';
}

void stamp(int i,int j){
    for(int k=0;k<8;k++){
        d[i+vx[k]][j+vy[k]]=1;
    }
}

bool canstamp(int i, int j){
    for(int k=0;k<8;k++){
        if(!isval(i+vx[k],j+vy[k]))return 0;
    }
    return 1;
}



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

     cin>>l>>c;
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++)
            cin>>m[i][j];
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(canstamp(i,j))stamp(i,j);
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]=='#'&&!d[i][j]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;

    
 
}