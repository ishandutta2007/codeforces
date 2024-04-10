#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
struct el{
    ull val;
    int ind;
    friend bool operator<(const el& e1, const el& e2){
        if(e1.val<e2.val){
            return true;
        }else if(e1.val>e2.val){
            return false;
        }else{
            return (e1.ind < e2.ind);
        }
    }
};
bool cmp(const el& e1, const el& e2){
    return (e1.ind < e2.ind);
}
set<el> a;
int n;
int k;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tmp;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> tmp;
        a.insert({tmp,i});
    }
    tmp = 0;
    set<el>::iterator it,pom;
    for(it=a.begin();it!=a.end();++it){
        if(!tmp){
            pom = it;
            tmp =1;
        }else{
            if(pom->val == it->val){
 
                a.erase(pom);
                ull add = it->val*2;
                a.insert({add,it->ind});
                pom = it;
                ++pom;
                a.erase(it);
                it = pom;
            }else{
                pom = it;
            }
 
        }
    }
    cout << a.size() << "\n";
    vector<el> res(a.begin(),a.end());
    sort(res.begin(),res.end(),cmp);
    for(el i : res){
        cout << i.val << " ";
    }
    cout << "\n";
 
 
 
 
 
    return 0;
}