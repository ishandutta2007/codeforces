#include <bits/stdc++.h>

using namespace std;

multiset<int> arr;
long long int distinct[1000010];

int main() {
    int n, target, b;
    long long int c, s=0;
    cin >> n >> target;
    for(int a=0; a<n; a++) {
        cin >> c;
        arr.insert(c);
    }
    for(int k : arr) {
        c=0;
        int t = k ^ target;
        b=distinct[k];
        if(b==0) {
            c+=arr.count(t);
            if(k==t) c--;
            if(c==0) distinct[k]=-1;
            else distinct[k]=c;
            b=c;
        }
        s+=max(0, b);
    }
    cout << s/2;
}