    #include<bits/stdc++.h>
    #define maxn 200010
    #define mod 1000000007
    #define ii pair<int,int>
    #define f first
    #define s second
    using namespace std;
    typedef long long ll;
    typedef long double ld;

    string a;

    bool pwur(int asf){
        for(int j=asf+1; j<a.size(); j++)
            if( a[j] < a[asf] )
                return true;
        return false;
    }

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int tc;
        cin >> tc;
        while( tc-- ){
            string b;
            cin >> a >> b;
            bool flag = 1;
            for(int i=0; i<a.size(); i++){
                if( pwur(i) ){
                    for(int j=i; j<a.size(); j++){
                        swap( a[i] , a[j] );
                        if( a < b && flag ){
                            cout << a << '\n';
                            flag = 0;
                        }
                        swap( a[i] , a[j] );
                    }
                    break;
                }
            }

            if( a < b && flag ){
                cout << a << '\n';
                continue;
            }
            if( flag ) cout << "---\n";
        }

        return 0;
    }