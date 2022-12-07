#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string col[] = {"purple", "green", "blue", "orange", "red", "yellow"};
    string type[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};

    int n;
    cin >> n;

    int vis[6];
    for(int i = 0; i < 6; ++i)
        vis[i] = 0;

    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < 6; ++j) {
            if(col[j] == s)
                vis[j] = 1;
        }
    }

    cout << (6 - n) << "\n";
    for(int i = 0; i < 6; ++i) {
        if(vis[i] == 0)
            cout << type[i] << "\n";
    }

    return 0;
}