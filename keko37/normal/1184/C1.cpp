#include <bits/stdc++.h>
using namespace std;

int N;
int x[50], y[50];
vector <int> xevi, yevi;

int main()
{
    cin >> N;
    N = 4 * N + 1;
    for (int i = 1; i <= N; i++)
    {
        cin >> x[i] >> y[i];
        xevi.push_back(x[i]);
        yevi.push_back(y[i]);
    }

    sort(xevi.begin(), xevi.end());
    xevi.erase(unique(xevi.begin(), xevi.end()), xevi.end());
    sort(yevi.begin(), yevi.end());
    yevi.erase(unique(yevi.begin(), yevi.end()), yevi.end());

    for (int i = 0; i < xevi.size() - 1; i++)
    {
        for (int j = i + 1; j < xevi.size(); j++)
        {
                for (int k = 0; k < yevi.size() - 1; k++)
                {
                    for (int l = k + 1; l < yevi.size(); l++)
                    {
                            vector <int> sol;
                            int cntx1 = 0, cntx2 = 0, cnty1 = 0, cnty2 = 0;
                            sol.clear();
                            bool da;
                            for (int m = 1; m <= N; m++)
                            {
                                da = 0;
                                if (x[m] != xevi[i] and x[m] != xevi[j] and y[m] != yevi[k] and y[m] != yevi[l])
                                {
                                    da = 1;
                                    sol.push_back(m);
                                }
                                if (x[m] == xevi[i])
                                {
                                    if (y[m] < min(yevi[k], yevi[l]) or y[m] > max(yevi[k], yevi[l]))
                                        {if (!da) {sol.push_back(m); da = 1;}}
                                    else cntx1++;
                                }
                                if (x[m] == xevi[j])
                                {
                                    if (y[m] < min(yevi[k], yevi[l]) or y[m] > max(yevi[k], yevi[l]))
                                        {if (!da) {sol.push_back(m); da = 1;}}
                                    else cntx2++;
                                }
                                if (y[m] == yevi[k])
                                {
                                    if (x[m] < min(xevi[i], xevi[j]) or x[m] > max(xevi[i], xevi[j]))
                                        {if (!da){sol.push_back(m); da = 1;}}
                                    else cnty1++;
                                }
                                if (y[m] == yevi[l])
                                {
                                    if (x[m] < min(xevi[i], xevi[j]) or x[m] > max(xevi[i], xevi[j]))
                                        {if (!da) {sol.push_back(m); da = 1;}}
                                    else cnty2++;
                                }
                            }

                            if (sol.size() == 1 and cntx1 >= (N / 4) and cntx2 >= (N / 4) and cnty1 >= (N / 4) and cnty2 >= (N / 4))
                            {
                                cout << x[sol[0]] << ' ' << y[sol[0]] << endl;
                                return 0;
                            }
                    }
                }
        }
    }
}
/*
2
1 1
2 1
5 1
7 1
6 2
6 3
4 3
3 3
1 2
*/