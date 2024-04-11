#include <bits/stdc++.h>
using namespace std;

#define MAXN 212345
#define int long long
#define pb push_back
#define inf LLONG_MAX
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

    char c;
    string s;
    cin>>c;
    for(int i=0;i<6;i++){
        char d;
        cin>>d;
        s+=d;
    }
    cout<<stoi(s)%2<<endl;
    return 0;
 
}