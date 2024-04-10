#include<bits/stdc++.h>

using namespace std;

int n;
int f[2000];
vector<int> g;

int main(){
    cin>>n;
    f[1] = 0;
    for(int i = 2; i <= n; i++){
        f[i] = 1;
        for(int j = 2; j < i; j++)
            if (i%j==0){
                f[i] = 0;
                break;
            }
    }
    int ans = 0;
    for(int i = 2; i <= n; i++)
        if (f[i]){
            int x = i;
            while (x <= n){
                ans++;
                g.push_back(x);
                x *= i;
            }
        }
    cout<<ans<<endl;
    if (g.size())
        printf("%d",g[0]);
    for(int i = 1; i < g.size(); i++)
        printf(" %d",g[i]);
    cout<<endl;
    return 0;
}