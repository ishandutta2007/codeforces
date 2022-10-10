    //start of jonathanirvings' template

    #define jonathan using
    #define ganteng namespace
    #define banget std
    #include <stdio.h>
    #include <iostream>
    #include <algorithm>
    #include <memory.h>
    #include <deque>
    #include <string>
    #include <string.h>
    #include <vector>
    #include <stack>
    #include <queue>
    #include <math.h>
    #include <stdlib.h>
    #include <map>
    jonathan ganteng banget;

    typedef long long LL;
    typedef vector <int> vi;
    typedef vector <vi> vii;
    typedef pair<int,int> pii;

    double EPS = 1e-6;
    int INF = 2000000000;
    long long INFF = 8000000000000000000LL;

    #define DEBUG printf("====TESTING====\n")
    #define FOR(a,b,c) for (int (a)=(b);(a)<(c);(a)++)
    #define FORN(a,b,c) for (int (a)=(b);(a)<=(c);(a)++)
    #define FORD(a,b,c) for (int (a)=(b);(a)>=(c);(a)--)
    #define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);(a)++)
    #define FORC(a,b,c) for (char (a)=(b);(a)<=(c);(a)++)
    #define fi first
    #define se second
    #define mp make_pair
    #define pb push_back
    #define SORT(v) sort(v.begin(),v.end())
    #define SORTA(arr,sz) sort(arr+1,arr+1+sz)

    //end of jonathanirvings' template

    string s = "6789TJQKA";
    char a,b,c,d;

    int main()
    {
        char trump;
        scanf("%c\n",&trump);
        scanf("%c%c %c%c",&a,&b,&c,&d);
        int rank1 = s.find(a);
        int rank2 = s.find(c);
        if (b == trump && d != trump)
        {
            printf("YES\n");
            return 0;
        }
        if (b != trump && d == trump)
        {
            printf("NO\n");
            return 0;
        }  
        if (rank1 > rank2 && b == d) printf("YES\n"); else printf("NO\n");
            return 0;
    }