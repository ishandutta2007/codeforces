#include <cstdio>

struct node {
    int fil, clus;
};

node takenBy[205];
int num, numF, numC[205], cluster[205][205];
int freePlc, totC, tem, curPlc, numMovs;
bool isTaken[205];

int numPrint;
node printOrder[410];

int main() {
    for (int i = 0; i < 205; i++) {
        takenBy[i].fil = takenBy[i].clus = -1;
    }
    scanf ("%d %d", &num, &numF);
    for (int i = 0; i < numF; i++) {
        scanf ("%d", &numC[i]);
        totC += numC[i];
        for (int p = 0; p < numC[i]; p++) {
            scanf ("%d", &tem);
            isTaken[tem] = true;
            cluster[i][p] = tem;
            takenBy[tem].fil = i;
            takenBy[tem].clus = p;
        }
    }
    for (int i = 1; i <= num; i++) {
        if (!isTaken[i]) {
            freePlc = i;
            break;
        }
    }
    curPlc = 1;
    for (int i = 0; i < numF; i++) {
        for (int p = 0; p < numC[i]; p++) {
            if (cluster[i][p] == curPlc) {
            } else {
                if (takenBy[curPlc].fil != -1) {
                    cluster[takenBy[curPlc].fil][takenBy[curPlc].clus] = freePlc;
                    takenBy[freePlc].fil = takenBy[curPlc].fil;
                    takenBy[freePlc].clus = takenBy[curPlc].clus;
                }
                if (curPlc == freePlc) {
                } else {
                    printOrder[numPrint].fil = curPlc;
                    printOrder[numPrint++].clus = freePlc;
                }
                printOrder[numPrint].fil = cluster[i][p];
                printOrder[numPrint++].clus = curPlc;
                freePlc = cluster[i][p];
            }
            curPlc++;
        }
    }
    printf ("%d\n", numPrint);
    for (int i = 0; i < numPrint; i++) {
        printf ("%d %d\n", printOrder[i].fil, printOrder[i].clus);
    }
    return 0;
}