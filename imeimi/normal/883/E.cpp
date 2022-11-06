/*
god taekyu
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;
char A[55];
char H[1005][55];
int m;
int vt[30];
int nun[1005];

int alpah[1005][33];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>A;
    cin>>m;
    for(int i=1;i<=m;i++) {
        cin>>H[i];
    }
    for(int i=0;i<n;i++) {
        if(A[i] != '*') {
            vt[A[i]-'a']=1;
        }
    }
    for(int j=0;j<n;j++) {
        if(A[j] == '*') {
            for(int i=1;i<=m;i++) {
                if(vt[H[i][j]-'a'] == 1) {
                    nun[i] = -1;
                }
            }
        }
    }
    for(int i=1;i<=m;i++) {
        for(int j=0;j<n;j++) {
            if(A[j] != '*') {
                if(A[j] != H[i][j]) nun[i]=-1;
            }
        }
    }
    
    for(int i=1;i<=m;i++) {
        if(nun[i] != -1) {
            for(int j=0;j<n;j++) {
                if(A[j]=='*') {
                    alpah[i][H[i][j]-'a']=1;
                }
            }
        }
    }
    int cnt=0;
    for(int j=0;j<26;j++) {
        if(vt[j]==1) continue;
        int flag = 0;
        for(int i=1;i<=m;i++) {
            if(nun[i] != -1 ) {
                if(alpah[i][j] == 0) {
                    flag=1;
                }
            }
        }
        if(flag==0) cnt++;
    }
    cout<<cnt;
    return 0;
}

/*
god taekyu
*/