#include<iostream>
#include<vector>

using namespace std;

int n, cnt, cik, sol=1;
int l[200005];
int bio[200005];
int pos[200005];
vector <int> v[200005];
int mod=1000000007;

void nadi (int cvor) {
    int curr=cvor;
    while (l[curr]!=cvor) {
        cik++;
        curr=l[curr];
    }
    cik++;
}

void dfs (int cvor) {
    bio[cvor]=1;
    if (bio[l[cvor]]==0) {
        dfs(l[cvor]);
    } else if (bio[l[cvor]]==1) {
        nadi(cvor);
    }
    bio[cvor]=2;
}

void skroz (int cvor) {
    cnt++;
    pos[cvor]=1;
    for (int i=0; i<v[cvor].size(); i++) {
        if (pos[v[cvor] [i]]==0) skroz(v[cvor] [i]);
    }
}

int main () {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> l[i];
        v[i].push_back(l[i]);
        v[l[i]].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        if (pos[i]==0) {
            cnt=0; cik=0;
            skroz(i);
            dfs(i);
            for (int j=0; j<cnt-cik; j++) {
                sol*=2;
                if (sol>=mod) sol-=mod;
            }
            int temp=1;
            for (int j=0; j<cik; j++) {
                temp*=2;
                if (temp>=mod) temp-=mod;
            }
            temp-=2;
            if (temp<0) temp+=mod;
            sol=((long long) sol)*((long long) temp)%mod;
        }
    }
    cout << sol;
    return 0;
}