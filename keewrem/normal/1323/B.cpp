#include <bits/stdc++.h>
using namespace std;
int n,m,k;
bool a[50000];
bool b[50000];
int main(){
    cin >> n >> m>>k;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];
    vector <int> va,vb;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i])count++;
        else{
            if(count!=0)va.push_back(count);
            count = 0;
        }
    }
    if(count!=0)va.push_back(count);
    count = 0;
    for(int i = 0; i < m; i++){
        if(b[i])count++;
        else{
            if(count!=0)vb.push_back(count);
            count = 0;
        }
    }
    if(count!=0)vb.push_back(count);
    long long ka = 0, kb = 0;
    long long res = 0;
    for(int i = 1; i*i <= k; i++){
        if(k%i!=0)continue;
        ka = 0; kb = 0;
        for(auto x: va){
            if (x>= i)ka+=x-i+1;
        }
        for(auto x: vb){
            if(x>= k/i)kb += x-(k/i)+1;
        }
        res += ka*kb;
        ka = 0; kb = 0;
        if(i*i == k)continue;
        for(auto x: vb){
            if (x>= i)ka+=x-i+1;
        }
        for(auto x: va){
            if(x>= k/i)kb += x-(k/i)+1;
        }
        res+=ka*kb;
    }
    cout << res << "\n";
    return 0;
}