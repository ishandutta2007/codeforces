#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>arr(n+1);
        for(int i = 1; i<=n; i++){
            cin >> arr[i];
        }
        reverse(arr.begin()+1,arr.end());
        vector<int>a;
        vector<int>b;
        a.push_back((int)1e7);
        b.push_back((int)1e7);
        bool f = true;
        for(int i = 1; i<=n; i++){
            if(i%2==1){
                if(a.back()>=b.back()){
                    if(arr[i]<=b.back()){
                        b.push_back(arr[i]);
                    }
                    else if(arr[i]<=a.back()){
                        a.push_back(arr[i]);
                    }
                    else{
                        f = false;
                    }
                }
                else{
                    if(arr[i]<=a.back()){
                        a.push_back(arr[i]);
                    }
                    else if(arr[i]<=b.back()){
                        b.push_back(arr[i]);
                    }
                    else{
                        f = false;
                    }
                }
            }
            else{
                if(a.size()>b.size()){
                    if(arr[i]>b.back()){
                        f = false;
                    }
                    b.push_back(arr[i]);
                }
                else{
                    if(arr[i]>a.back()){
                        f = false;
                    }
                    a.push_back(arr[i]);
                }
            }
        }
        a.erase(a.begin());
        b.erase(b.begin());
        /*
        for(int nxt: a){
            cout << nxt << " ";
        }
        cout << "\n";
        for(int nxt: b){
            cout << nxt << " ";
        }
        cout << "\n";
        */
        vector<int>vec;
        if(n%2==1){
            if(a.size()<b.size())swap(a,b);
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            //vector<int>vec;
            vec.push_back(a[0]);
            for(int i = 0; i<n/2; i++){
                int x = b[i]; int y = a[i+1];
                if(x<y)swap(x,y);
                vec.push_back(y); vec.push_back(x);
            }
            //reverse(vec.begin(),vec.end());
            for(int i = 1; i<vec.size(); i++){
                if(vec[i]<vec[i-1])f = false;
            }
        }
        else{
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            
            for(int i = 0; i<n/2; i++){
                int x = a[i]; int y = b[i];
                if(x<y)swap(x,y);
                vec.push_back(y); vec.push_back(x);
            }
            //reverse(vec.begin(),vec.end());
            for(int i = 1; i<vec.size(); i++){
                if(vec[i]<vec[i-1])f = false;
            }
        }
        
        /*for(int nxt: vec){
            cout << nxt << " ";
        }
        */
        cout << (f?"YES":"NO") << "\n";
    }
    return 0;
}