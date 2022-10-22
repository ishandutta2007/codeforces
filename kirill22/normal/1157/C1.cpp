#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int ans = 1 ,ansi = 0;
    if (a[0] > a[n - 1]){
        int x = 1;
        ansi = 1;
        while(x < n){
            if (a[x] > a[x - 1]){
                x++;
                ansi++;
            }
            else{
                break;
            }
        }
        int mini = a[n-1];
        int l = 0,r = n - 2;
        vector<char> A;
        A.push_back('R');
        while(l <= r){
            if(a[l] < a[r]){
                if (a[l] < mini){
                    if (a[r] < mini){
                        break;
                    }
                    else{
                        A.push_back('R');
                    ans++;
                    mini = a[r];
                    r--;
                    }
                }
                else{
                    A.push_back('L');
                    ans++;
                    mini = a[l];
                    l++;
                }
            }else{
                if (a[r] < mini){
                    if (a[l] < mini){
                        break;
                    }
                    else{
                        A.push_back('L');
                    ans++;
                    mini = a[l];
                    l++;
                    }
                }
                else{
                    A.push_back('R');
                    ans++;
                    mini = a[r];
                    r--;
                }
            }
        }
        if (ansi > ans){
                cout << ansi << endl;
            for(int i =0;i<ansi;i++){
                cout << "L" ;
            }
            return 0;
        }
        else{
            cout << ans << endl;
            for(int i =0;i<A.size();i++){
                cout << A[i] ;
            }
            return 0;
        }


    }
    else{
        int x = n - 2;
        ansi = 1;
        while(x > -1){
            if (a[x] > a[x + 1]){
                x--;
                ansi++;
            }
            else{
                break;
            }
        }
        int mini = a[0];
        int l = 1,r = n - 1;
        vector<char> A;
        A.push_back('L');
        while(l <= r){
            if(a[l] < a[r]){
                if (a[l] < mini){
                    if (a[r] < mini){
                        break;
                    }
                    else{
                        A.push_back('R');
                    ans++;
                    mini = a[r];
                    r--;
                    }
                }
                else{
                    A.push_back('L');
                    ans++;
                    mini = a[l];
                    l++;
                }
            }else{
                if (a[r] < mini){
                    if (a[l] < mini){
                        break;
                    }
                    else{
                        A.push_back('L');
                    ans++;
                    mini = a[l];
                    l++;
                    }
                }
                else{
                    A.push_back('R');
                    ans++;
                    mini = a[r];
                    r--;
                }
            }
        }
        if (ansi > ans){
                cout << ansi << endl;
            for(int i =0;i<ansi;i++){
                cout << "R" ;
            }
            return 0;
        }
        else{
            cout << ans << endl;
            for(int i =0;i<A.size();i++){
                cout << A[i] ;
            }
            return 0;
        }
    }

}