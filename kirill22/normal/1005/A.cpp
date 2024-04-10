#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int a,b,c=0,d=0;
    cin >> a;
    vector <int> ans;
    for(int i=0;i<a;i++){
        cin >> b;
        if (b>c){
            d++;
            c=b;
        }
        else if (c>=b){
            ans.push_back(d);
            d=1;
            c=b;
        }
    }
    ans.push_back(b);
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

}