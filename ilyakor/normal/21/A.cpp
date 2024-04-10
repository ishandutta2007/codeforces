#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

bool good(char c)
{
    return isalpha(c) || isdigit(c) || c == '_';
}

void parse_word(string s)
{
    if (sz(s) < 1 || sz(s) > 16)
        throw 57;
    for (int i = 0; i < sz(s); i++)
        if (!good(s[i]))
            throw 57;
}

void parse_user(string s)
{
    //cerr << "user " << s << "\n";
    parse_word(s);
}

void parse_res(string s)
{
    parse_word(s);
}

void parse_host(string s)
{
    //cerr << "host " << s << "\n";
    if (sz(s) < 1 || sz(s) > 32)
        throw 57;
    string cur;
    for (int i = 0; i < sz(s); i++)
    {
        if (s[i] == '.')
        {
            parse_word(cur);
            cur = "";
        }
        else
            cur += s[i];
    }
    parse_word(cur);
}


int main()
{
    try
    {
        string s;
        cin >> s;
        int cur = 0;
        string username;
        while (cur < sz(s) && s[cur] != '@')
        {
            username += s[cur];
            cur++;
        }
        if (cur >= sz(s) || s[cur] != '@')
            throw -1;
        parse_user(username);
        cur++;
        string host;
        while (cur < sz(s) && s[cur] != '/')
        {
            host += s[cur];
            cur++;
        }
        parse_host(host);
        if (cur < sz(s))
        {
            cur++;
            string res;
            while (cur < sz(s))
                res += s[cur++];
            parse_res(res);
        }
    }
    catch(int)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}