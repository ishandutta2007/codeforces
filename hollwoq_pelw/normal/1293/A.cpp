#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t){
        t--;
        int n,s,k,ele;
        cin >> n >> s >> k;
        set<int> A;
        for (int i = 0; i < k; i++){
            cin >> ele;
            A.insert(ele);
        }
        int r = 0;
        while ((A.count(s-r) || (s-r) < 1)&&(A.count(s+r) || (s+r) > n)){
            r ++;
        }
        cout << r << endl;
    }
    return 0;
}