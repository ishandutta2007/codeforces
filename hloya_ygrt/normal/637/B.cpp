#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const int sz = 3;
const double eps=1e-9;
const int maxn = 2e5+500, base = 1e9+7,maxm= 10;

set<string> s;
string input[maxn];
int main()
{
    int pr = 0;
    int n;
    fast_io;
    cin.tie(0);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> input[i];
    }
    for (int i=n-1;i>=0;i--){
        if (s.find(input[i]) == s.end()){
            s.insert(input[i]);
            cout<<input[i]<<'\n';
        }
    }
}