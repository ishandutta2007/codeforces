    #include<bits/stdc++.h>
    using namespace std;
    int val[15];
    int main()
    {
        string a;
        cin>>a;
        for(int x=0;x<a.size();x++)
            val[x] = a[x] - 'A';
        for(int x=2;x<a.size();x++)
            if(val[x]!=(val[x-1] + val[x-2])%26)
            {
                cout<<"NO";
                return 0;
            }
        cout<<"YES";
        return 0;
    }