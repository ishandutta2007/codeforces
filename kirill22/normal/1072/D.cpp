 #include <bits/stdc++.h>

using namespace std;
typedef int itn;
typedef int tin;
typedef int tni;
typedef int nit;
typedef int nti;
typedef long long ll;

typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int m[2000+1][2000+1];
int V[2000+1][2000+1];
vector<pii> M;
int s;


int main() {
    int n, k,ans=0;
    cin >> n >> k;
    char a[n][n];
    string si;
    for(int i=0;i<n;i++){
            cin  >> si;
        for(int u=0;u<n;u++){
            a[i][u]=si[u];
        }
    }
    if (n==1){
        if (k>0){
            cout << "a";
        }
        else{
            cout << a[0][0];
        }
        return 0;
    }


    for(int i=0;i<n;i++){
        for(int u=0;u<n;u++){
            if (i==0 && u==0){
                if (a[i][u]!='a'){
                     m[i][u]++;
                }
            }
            else if(i==0){
                m[i][u]=m[i][u-1];
                if (a[i][u]!='a'){
                     m[i][u]++;
                }
            }
            else if(u==0){
                m[i][u]=m[i-1][u];
                if (a[i][u]!='a'){
                     m[i][u]++;
                }
            }
            else{
                m[i][u]=min(m[i-1][u],m[i][u-1]);
                if (a[i][u]!='a'){
                     m[i][u]++;
                }
            }
            if (m[i][u]<=k){
                if (i+u+1==ans){
                    M.push_back(make_pair(i,u));

                }
                if (i+u+1>ans){
                    ans=i+u+1;
                    int s=M.size();
                    for (int i=0;i<s;++i){
                        M.pop_back();
                    }
                    M.push_back(make_pair(i,u));

                }

            }

        }
    }
    for(int i=0;i<ans;i++){
        cout << "a";
    }
    if (ans>=2*n-1){
        return 0;
    }
    char c='z';
    if (ans==0){
        M.push_back(make_pair(0,0));
        ans++;
        cout << a[0][0];
        if (n>1) {
            c= min(a[0][1], a[1][0]);

        }

    }


    for(int i=0;i<M.size();i++){
        if (M[i].first+1<n){
            c=min(c,a[M[i].first+1][M[i].second]);
        }
        if (M[i].second+1<n){
            c=min(c,a[M[i].first][M[i].second+1]);
        }

    }
    for(int i=ans+1;i<2*n-1;i++){
        vector<pii> M1;

        char co='z';
        for(int u=0;u<M.size();u++){

            int x=M[u].first;
            int y=M[u].second;
            if (x+1<n && V[x+1][y]==0){
                if (a[x+1][y]==c){
                    V[x+1][y]=1;
                    M1.push_back(make_pair(x+1,y));
                    if (x+2<n){
                        co=min(co,a[x+2][y]);
                    }
                    if (y+1<n){
                    co=min(co,a[x+1][y+1]);
                    }

                }
            }

            if (y+1<n && V[x][y+1]==0){

                if (a[x][y+1]==c){
                    V[x][y+1]=1;
                    M1.push_back(make_pair(x,y+1));

                    if (y+2<n){
                        co=min(co,a[x][y+2]);
                    }
                    if (x+1<n){
                    co=min(co,a[x+1][y+1]);
                    }


                }
            }
        }
        cout << c;
        c=co;
        s=M.size();
        for (int ii=0;ii<s;++ii){
                M.pop_back();
        }
        s=M1.size();
        //cout << endl << i << endl;


        for (int ii=0;ii<s;++ii){
                M.push_back(make_pair(M1[ii].first,M1[ii].second));
                //cout << M1[ii].first << " " << M1[ii].second;


        }
        //cout << endl;

        s=M1.size();
        for (int ii=0;ii<s;++ii){
                M1.pop_back();
        }

    }
    cout << a[n-1][n-1];








    return 0;
}