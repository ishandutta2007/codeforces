 #include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int n,m,c,f,l,k,ans=0;
    cin >> n >> m ;
    int a[n][2];
    vector<int> lo;
    for(int i=0;i<n;i++){
            cin >> a[i][0] >> a[i][1];
    }
    for(int i=1;i<=m;i++){
        bool flag=true;
        for(int u=0;u<n;u++){
            if ((i >=a[u][0] && i<=a[u][1])){
                flag=false;
                break;
            }
        }
        if (flag){
                ans++;
                lo.push_back(i);

        }
    }
    cout << ans;
    cout << endl;
    for(int i=0;i<ans;i++){
        cout << lo[i] << " ";
    }









    return 0;
}