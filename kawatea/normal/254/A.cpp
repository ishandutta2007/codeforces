#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector <int> v[5000];

int main()
{
    int n, i, j;
    FILE *fp;
    
    fp = fopen("input.txt", "r");
    
    fscanf(fp, "%d", &n);
    
    for (i = 0; i < 2 * n; i++) {
        int x;
        
        fscanf(fp, "%d", &x);
        
        x--;
        
        v[x].push_back(i + 1);
    }
    
    fclose(fp);
    
    fp = fopen("output.txt", "w");
    
    for (i = 0; i < 5000; i++) {
        if (v[i].size() % 2 == 1) {
            fprintf(fp, "-1\n");
            
            fclose(fp);
            
            return 0;
        }
    }
    
    for (i = 0; i < 5000; i++) {
        for (j = 0; j < v[i].size(); j += 2) {
            fprintf(fp, "%d %d\n", v[i][j], v[i][j + 1]);
        }
    }
    
    fclose(fp);
    
    return 0;
}