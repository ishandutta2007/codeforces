#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,k,res=0;
        cin >> n;
        unordered_map<int, int> s; 
        while (n){
            n--;
            cin >> k;
            int a = 0;
            while(k%2==0){
                k/=2;
                a++;
            }
            if (s.count(k)){
                if (s[k] < a){
                    s[k] = a;
                }
            }else {
                s[k]=a;
            }
        }
        for (auto p = s.begin(); p != s.end(); p++){
            res += p->second;
        }
        cout << res << endl;
    }
}