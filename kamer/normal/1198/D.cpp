#include <vector>
#include <iostream>
#include <algorithm>
 
const int MAX_N = 50;
// i, j, row/col, dist
// 0 is row, 1 is col
bool isEmpty[MAX_N][MAX_N][2][MAX_N];
// min_i, min_j, max_i, max_j
int result[MAX_N][MAX_N][MAX_N][MAX_N];
int n;
bool table[MAX_N][MAX_N];

void initTable(void) {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            std::cin >> c;
            if (c == '#') {
                table[i][j] = true;
            } else {
                table[i][j] = false;
            }
        }
    }
}

void initLookups(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int col = 0; col < 2; col++) {
                for (int d = 0; d < n; d++) {
                    if (col == 0 && j + d >= n)
                        break;
                    if (col == 1 && i + d >= n)
                        break;
                    if (d == 0)
                        isEmpty[i][j][col][d] = !table[i][j];
                    else {
                        int i1 = i, j1 = j;
                        if (col == 0)
                            j1 = j + d;
                        else
                            i1 = i + d;
                        isEmpty[i][j][col][d] = (!table[i1][j1]) && isEmpty[i][j][col][d-1];
                    }
                }
            }
        }
    }
}

void initResults(int n) {
    for (int a = 0; a < n; a++)
        for(int b = 0; b < n; b++)
            for (int c = 0; c < n; c++)
                for (int d = 0; d < n; d++)
                    result[a][b][c][d] = -1;
}
 
int fillResults(int i1, int j1, int i2, int j2) {
    if (i1 > i2 || j1 > j2) {
        return 0;
    }
    
    if (result[i1][j1][i2][j2] != -1)
        return result[i1][j1][i2][j2];
        
    if (i1 == i2 && j1 == j2) {
        if (table[i1][j1])
            result[i1][j1][i2][j2] = 1;
        else
            result[i1][j1][i2][j2] = 0;
        return result[i1][j1][i2][j2];
    }
    
    if (j2 - j1 > i2 - i1) {
        if (isEmpty[i1][j1][1][i2 - i1]) {
            result[i1][j1][i2][j2] = fillResults(i1, j1 + 1, i2, j2);
            return result[i1][j1][i2][j2];
        }
        
        if (isEmpty[i1][j2][1][i2 - i1]) {
            result[i1][j1][i2][j2] = fillResults(i1, j1, i2, j2 - 1);
            return result[i1][j1][i2][j2];
        }
        
        int bestResult = j2 - j1 + 1;
        for (int i = j1 + 1; i < j2; i++) {
            if (isEmpty[i1][i][1][i2 - i1]) {
                int currentResult = fillResults(i1, j1, i2, i - 1) +
                                    fillResults(i1, i + 1, i2, j2);
                bestResult = std::min(bestResult, currentResult);
            }
        }
        
        result[i1][j1][i2][j2] = bestResult;
        return result[i1][j1][i2][j2];
    } else {
        if (isEmpty[i1][j1][0][j2 - j1]) {
            result[i1][j1][i2][j2] = fillResults(i1 + 1, j1, i2, j2);
            return result[i1][j1][i2][j2];
        }
        
        if (isEmpty[i2][j1][0][j2 - j1]) {
            result[i1][j1][i2][j2] = fillResults(i1, j1, i2 - 1, j2);
            return result[i1][j1][i2][j2];
        }
        
        int bestResult = i2 - i1 + 1;
        for (int i = i1 + 1; i < i2; i++) {
            if (isEmpty[i][j1][0][j2 - j1]) {
                int currentResult = fillResults(i1, j1, i - 1, j2) +
                                    fillResults(i + 1, j1, i2, j2);
                bestResult = std::min(bestResult, currentResult);
            }
        }
        
        result[i1][j1][i2][j2] = bestResult;
        return result[i1][j1][i2][j2];
    }
}
 
int main(void) {
    initTable();
    
    initLookups(n);

    initResults(n);
    
    std::cout << fillResults(0, 0, n-1, n-1);
    
    return 0;
}