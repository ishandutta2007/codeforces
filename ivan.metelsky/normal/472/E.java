import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class ProblemE {
    int n, m;
    int[][] cur;
    int[][] fin;

    List<Integer> ansX = new ArrayList<Integer>();
    List<Integer> ansY = new ArrayList<Integer>();

    void printMove(int a, int b) {
        System.out.println((a+1)+" "+(b+1));
    }

    void solveOne() {
        for (int from = 0; from < n+m-1; from++) {
            for (int to = 0; to < n+m-1; to++) {
                if (from == to) {
                    continue;
                }

                int[][] res = new int[n][m];
                for (int i=0; i<n; i++) {
                    for (int j=0; j<m; j++) {
                        res[i][j] = cur[i][j];
                    }
                }

                if (from < to) {
                    for (int i = from; i < to; i++) {
                        if (n == 1) {
                            int tmp = res[0][i];
                            res[0][i] = res[0][i+1];
                            res[0][i+1] = tmp;
                        } else {
                            int tmp = res[i][0];
                            res[i][0] = res[i+1][0];
                            res[i+1][0] = tmp;
                        }
                    }
                } else {
                    for (int i = from; i > to; i--) {
                        if (n == 1) {
                            int tmp = res[0][i];
                            res[0][i] = res[0][i-1];
                            res[0][i-1] = tmp;
                        } else {
                            int tmp = res[i][0];
                            res[i][0] = res[i-1][0];
                            res[i-1][0] = tmp;
                        }
                    }
                }

                boolean ok = true;
                for (int i=0; i<n; i++) {
                    for (int j=0; j<m; j++) {
                        if (res[i][j] != fin[i][j]) {
                            ok = false;
                        }
                    }
                }

                if (ok) {
                    System.out.println(Math.abs(from - to));

                    if (n == 1) {
                        printMove(0, from);
                    } else {
                        printMove(from, 0);
                    }

                    if (from < to) {
                        for (int i = from; i < to; i++) {
                            if (n == 1) {
                                printMove(0, i + 1);
                            } else {
                                printMove(i + 1, 0);
                            }
                        }
                    } else {
                        for (int i = from; i > to; i--) {
                            if (n == 1) {
                                printMove(0, i - 1);
                            } else {
                                printMove(i - 1, 0);
                            }
                        }
                    }

                    System.exit(0);
                }
            }
        }

        System.out.println(-1);
        System.exit(0);
    }

    void goTo(int i, int j) {
        int curI = ansX.get(ansX.size() - 1);
        int curJ = ansY.get(ansY.size() - 1);

        int tmp = cur[curI][curJ];
        cur[curI][curJ] = cur[i][j];
        cur[i][j] = tmp;

        ansX.add(i);
        ansY.add(j);
    }

    void makeSwap(int i1, int j1, int i2, int j2) {
        int curI = ansX.get(ansX.size() - 1);
        int curJ = ansY.get(ansY.size() - 1);

        if (curI == i1 && curJ == j1) {
            goTo(i2, j2);
            return;
        }

        if (curI == i2 && curJ == j2) {
            goTo(i1, j1);
            return;
        }

        int dst1 = Math.max(Math.abs(curI - i1), Math.abs(curJ - j1));
        int dst2 = Math.max(Math.abs(curI - i2), Math.abs(curJ - j2));

        if (dst1 == 1 && dst2 == 1) {
            goTo(i1, j1);
            goTo(i2, j2);
            goTo(curI, curJ);
            return;
        }

        int nextI = -1, nextJ = -1, bestDst = 100;
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (di == 0 && dj == 0) {
                    continue;
                }
                int candI = curI + di, candJ = curJ + dj;
                if (candI < 0 || candI >= n || candJ < 0 || candJ >= m) {
                    continue;
                }
                if (candI == i1 && candJ == j1) {
                    continue;
                }
                if (candI == i2 && candJ == j2) {
                    continue;
                }
                int dst = Math.max(Math.abs(candI - i1), Math.abs(candJ - j1)) + Math.max(Math.abs(candI - i2), Math.abs(candJ - j2));
                if (dst < bestDst) {
                    bestDst = dst;
                    nextI = candI;
                    nextJ = candJ;
                }
            }
        }

        goTo(nextI, nextJ);
        makeSwap(i1, j1, i2, j2);
        goTo(curI, curJ);
    }

    public void solve() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        n = sc.nextInt();
        m = sc.nextInt();
        cur = new int[n][m];
        fin = new int[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cur[i][j] = sc.nextInt();
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                fin[i][j] = sc.nextInt();
            }
        }

        if (n == 1 || m == 1) {
            solveOne();
        }

        ansX.add(0);
        ansY.add(0);

        boolean[][] fixed = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ii = -1, jj = -1;
                for (int x = 0; x < n && ii == -1; x++) {
                    for (int y = 0; y < m && ii == -1; y++) {
                        if (!fixed[x][y] && cur[x][y] == fin[i][j]) {
                            ii = x;
                            jj = y;
                        }
                    }
                }
                if (ii == -1) {
                    System.out.println(-1);
                    System.exit(0);
                }
                while (ii != i || jj != j) {
                    int iii = -1, jjj = -1;
                    int bestDst = 1000;
                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            if (di == 0 && dj == 0) {
                                continue;
                            }
                            if (ii + di >= 0 && ii + di < n && jj + dj >= 0 && jj + dj < m && !fixed[ii + di][jj + dj] && Math.abs(i - ii - di) + Math.abs(j - jj - dj) < bestDst) {
                                bestDst = Math.abs(i - ii - di) + Math.abs(j - jj - dj);
                                iii = ii + di;
                                jjj = jj + dj;
                            }
                        }
                    }
                    makeSwap(ii, jj, iii, jjj);
                    ii = iii; jj = jjj;
                }
                fixed[i][j] = true;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(ansX.size() - 1);
        sb.append("\n");
        for (int i=0; i < ansX.size(); i++) {
            sb.append((ansX.get(i) + 1) + " " + (ansY.get(i) + 1) + "\n");
        }

        System.out.print(sb.toString());
    }

    public static void main(String[] args) throws Exception {
        new ProblemE().solve();
   }
}