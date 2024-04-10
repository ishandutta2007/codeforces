 #include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,o=1;

string s,t,rs,rt;
vector<int>ans;

 main() {
    cin >> n >> k >> m;
    if (k*(n-1)<m || m<k){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i=k;i>0;i--){
        int d;
        if (m-i+1<n-1){
            d=m-i+1;
        }
        else{
            d=n-1;
        }
        if (o-d>0){
            o=o-d;
        }
        else{
            o=o+d;
        }
        cout << o << " ";
        m-=d;

    }


    return 0;
}