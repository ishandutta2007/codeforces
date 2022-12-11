#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector <vector <int> > matr(n, vector <int> (m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> matr[i][j];
    }

    vector <vector <int> > yahubbot(n, vector <int> (m));
    yahubbot[n - 1][m - 1] = matr[n - 1][m - 1];
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
    {
        if (i < n - 1) yahubbot[i][j] = max (yahubbot[i][j], yahubbot[i + 1][j] + matr[i][j]);
        if (j < m - 1) yahubbot[i][j] = max (yahubbot[i][j], yahubbot[i][j + 1] + matr[i][j]);
    }

    vector <vector <int> > yahubtop (n, vector <int> (m));
    yahubtop[0][0] = matr[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
    {
        if (i > 0) yahubtop[i][j] = max (yahubtop[i][j], yahubtop[i - 1][j] + matr[i][j]);
        if (j > 0) yahubtop[i][j] = max (yahubtop[i][j], yahubtop[i][j - 1] + matr[i][j]);
    }

    vector <vector <int> > yahubinatop (n, vector <int> (m));
    yahubinatop[0][m - 1] = matr[0][m - 1];
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--)
    {
        if (i > 0) yahubinatop[i][j] = max (yahubinatop[i][j], yahubinatop[i - 1][j] + matr[i][j]);
        if (j < m - 1) yahubinatop[i][j] = max (yahubinatop[i][j], yahubinatop[i][j + 1] + matr[i][j]);
    }

    vector <vector <int> > yahubinabot (n, vector <int> (m));
    yahubinabot[n - 1][0] = matr[n - 1][0];
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
    {
        if (i < n - 1) yahubinabot[i][j] = max (yahubinabot[i][j], yahubinabot[i + 1][j] + matr[i][j]);
        if (j > 0) yahubinabot[i][j] = max (yahubinabot[i][j], yahubinabot[i][j - 1] + matr[i][j]);
    }

    int otv = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
    {
        //cout << i << " " << j << " " << otv << "\n";
        int x = 0;
        if (i > 0 && j > 0)
        {
        x += yahubtop[i - 1][j];
        x += yahubinabot[i][j - 1];
        if (j < m - 1) x += yahubinatop[i][j + 1];
        if (i < n - 1) x += yahubbot[i + 1][j];
        if ((i == n - 1 && j != m - 1) || (j == m - 1 && i != 0)) x = 0;
        otv = max (otv, x);
        //cout << "pitrik1";
        }
        x = 0;
        if (j > 0 && i < n - 1)
        {
        x += yahubtop[i][j - 1];
        x += yahubinabot[i + 1][j];
        if (j < m - 1) x += yahubbot[i][j + 1];
        if (i > 0) x += yahubinatop[i - 1][j];
        if ((j == m - 1 && i != n - 1) || (i == 0 && j != m - 1)) x = 0;
        otv = max (otv, x);
        }
        //cout << i << " " << j << " " << otv << "\n";
        //otv = max (otv, yahubtop[i][j] + yahubbot[i][j] - 2 * matr[i][j] + yahubinabot[i][j] + yahubinatop[i][j] - 2 * matr[i][j]);
    }

    cout << otv;

}