 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;





int main() {
    int n,k,u=0;
    cin >> n;
    int a[n];
    int m[1000]={0};
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]++;
    }

    int ans=0;
    bool flag=true;
    for(int i=1;i<900;i++){
        if (flag){
            if (m[i]>2){
                flag=false;
                u=i;

            }
        }
        if (m[i]==1){
            ans++;
        }

    }

    if (ans%2==1 && flag){
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    int ko=ans/2;
    if (ans%2==0){
        for(int i=0;i<n;i++){
            if (m[a[i]]==1 && ko>0){
                ko--;
                cout << "A";
                continue;
            }
            else{
                cout << "B";
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if (m[a[i]]==1 && ko>0){
                ko--;
                cout << "A";
                continue;
            }
            else if (a[i]==u && (! flag)){
                cout << "A";
                flag=true;
            }
            else{
                cout << "B";
            }
        }
    }











    return 0;
}