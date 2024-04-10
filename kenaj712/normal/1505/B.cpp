    #include<bits/stdc++.h>
    using namespace std;
    int f(int a)
    {
        int sum = 0;
        while(a != 0)
        {
            sum += a%10;
            a/=10;
        }
        return sum;
    }
    int main()
    {
        //ios_base::sync_with_stdio(0);
        //cin.tie(0);
        int a;
        cin>>a;
        while(a >= 10)
            a = f(a);
        cout<<a;
        return 0;
    }