#include <bits/stdc++.h>
using namespace std;

string str, x;
int ind[1000000];

bool nadji(string v){
    int it=0;
    for(unsigned i=0; i<v.size(); i++){
            if(v[i] == x[it])it++;
            if(it == x.size()) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int last=0;
    cin >> str >> x;
    for(unsigned i=0; i<str.size(); i++) cin >> ind[i];
    int l=1, r=str.size();
    while(l<=r){
        int mid = (l+r)/2;
        vector <int> vec;
        for(int  it=mid; it<str.size(); it++){
            vec.push_back(ind[it]-1);
        }
        sort(vec.begin(), vec.end());
        string v = "";
        for(unsigned it=0; it<vec.size(); it++) v += str[vec[it]];
        if(nadji(v)){last = mid; l = mid+1;}
        else r = mid-1;
    }
    cout << last;
    return 0;
}