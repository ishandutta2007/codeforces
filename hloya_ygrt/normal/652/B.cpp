#include <bits/stdc++.h>

using namespace std;

int a[1001];

int main()
{
    int n;
    scanf("%d", &n);

    for (int i=0;i<n;i++){
        scanf("%d", a + i);
    }
    sort(a, a + n);
    vector<int> f, s;
    for (int i=0;i<n/2;i++){
        f.push_back(a[i]);
      //  cerr << f.back() << ' ';
    }
    //cerr  << endl;
    for (int i=n/2;i<n;i++){
        s.push_back(a[i]);
    //    cerr << s.back() << ' ';
    }

    if (s.size() > f.size()){
        f.push_back(s.front());
        s.erase(s.begin());
    }
    bool t = 1;
    int i1, i2;
    i1 = i2 = 0;
    for (int i=0;i<n;i++,t^=1){
        if (t)
            printf("%d ",f[i1++]);
        else
            printf("%d ",s[i2++]);
    }

}