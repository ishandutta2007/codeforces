#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'000'010
#define double long double
#define f first
#define s second
#define eps 1e-11
#define pb push_back

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(5);
    cout.setf(ios::fixed);

    string a,b;
    cin>>a>>b;
    int uns=0,zer=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='1')uns++;
        else zer++;
    }
    vector<int> z=z_function(b);
    int coisa=b.size();
    for(int i=0;i<z.size();i++){
        if(z[i]==z.size()-i){
            coisa=i;
            break;
        }
    }
    //cout<<coisa<<endl;
    string resp;
    bool deuruim=0;
    int i=0;
    while(uns||zer){
        if(i==b.size())i=b.size()-coisa;
        if(deuruim && uns){
            resp.pb('1');
            uns--;
        }
        else if(deuruim && zer){
            resp.pb('0');
            zer--;
        }
        else if(uns && b[i]=='1'){
            resp.pb('1');
            uns--;
            i++;
        }
        else if(zer && b[i]=='0'){
            resp.pb('0');
            zer--;
            i++;
        }
        else{
            deuruim=1;
        }
    }
    cout<<resp<<endl;

    return 0;
}