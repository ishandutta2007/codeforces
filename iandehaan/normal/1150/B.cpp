#include <iostream>
using namespace std;
bool board[60][60];
int n;

bool works(int r, int c) {
    if (r == 0 || r == n-1 || c == 0 || c == n-1) {
        return false;
    }
    if (board[r][c] == true || board[r-1][c] == true || board[r+1][c] == true || board[r][c-1] == true || board[r][c+1] == true) {
        return false;
    }
    return true;
}

void place (int r, int c) {
    board[r][c] = true;
    board[r-1][c] = true;
    board[r+1][c] = true;
    board[r][c-1] = true;
    board[r][c+1] = true;
}

int main() {
    //int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        char x;
        cin >> x;
        if (x == '#') {
            board[i][j] = 1;
        } else {
            board[i][j] = 0;
        }
    }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (works(i, j)) {
                place(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == false) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}