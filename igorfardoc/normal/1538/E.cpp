#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int get_ans(string a)
{
    int n = a.length();
    int res = 0;
    for(int i = 0; i < n - 3; i++)
    {
        if(a[i] == 'h' && a[i + 1] == 'a' && a[i + 2] == 'h' && a[i + 3] == 'a')
        {
            ++res;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<string, int> d;
        vector<string> start1;
        vector<string> end1;
        vector<ll> ans;
        for(int i = 0; i < n; i++)
        {
            string s1;
            cin >> s1;
            string op;
            cin >> op;
            if(op == ":=")
            {
                
                string s;
                cin >> s;
                int res = get_ans(s);
                int id1 = ans.size();
                if(d.find(s1) != d.end())
                {
                    id1 = d[s1];
                }
                else
                {
                    ans.push_back(0);
                    start1.push_back("");
                    end1.push_back("");
                }
                ans[id1] = res;
                string st = s;
                string fin = s;
                if(s.size() > 3)
                {
                    st = "";
                    fin = "";
                    for(int i = 0; i < 3; i++)
                    {
                        st += s[i];
                        fin += s[(int)s.size() - 3 + i];
                    }
                }
                start1[id1] = st;
                end1[id1] = fin;
                d[s1] = id1;
                if(i == n - 1)
                {
                    cout << ans[id1] << '\n';
                }
            }
            else
            {
                string s2, s3;
                cin >> s2;
                cin >> s3 >> s3;
                int id1 = ans.size();
                int id2 = d[s2];
                int id3 = d[s3];
                if(d.find(s1) != d.end())
                {
                    id1 = d[s1];
                }
                else
                {
                    ans.push_back(0);
                    start1.push_back("");
                    end1.push_back("");
                }
                ll anshere = ans[id2] + ans[id3];
                string middle = end1[id2] + start1[id3];
                anshere += get_ans(middle);
                string starthere, endhere;
                if(start1[id2].length() == 3)
                {
                    starthere = start1[id2];
                }
                else
                {
                    starthere = start1[id2];
                    for(int j = 0; j < min(start1[id3].length(), 3 - start1[id2].length()); j++)
                    {
                        starthere += start1[id3][j];
                    }
                }
                if(end1[id3].length() == 3)
                {
                    endhere = end1[id3];
                }
                else
                {
                    endhere = "";
                    int need = 3 - end1[id3].length();
                    for(int j = max(0, (int)end1[id2].length() - need); j < end1[id2].length(); j++)
                    {
                        endhere += end1[id2][j];
                    }
                    endhere += end1[id3];
                }
                d[s1] = id1;
                start1[id1] = starthere;
                end1[id1] = endhere;
                ans[id1] = anshere;
                if(i == n - 1)
                {
                    cout << ans[id1] << '\n';
                }
                //cout << start1[id1] << ' ' << end1[id1] << endl;
            }
        }
    }
}