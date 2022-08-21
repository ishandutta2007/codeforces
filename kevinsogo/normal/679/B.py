x = {}
x[0] = 0
x[1] = 1
x[2] = 2
x[3] = 3
x[4] = 4
x[5] = 5
x[6] = 6
x[7] = 7
x[8] = 15
x[9] = 23
x[10] = 50
x[11] = 114
x[12] = 330
x[13] = 1330
x[14] = 10591
x[15] = 215970
x[16] = 19464802
x[17] = 16542386125
x[18] = 409477218238718
x[19] = 1594640520554911022654

def bestup2(n):
    c = 0
    while x[c] <= n: c += 1
    return c-1

mini = [0, 1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 14, 15, 15, 15, 15, 15]

def bestbl2(n):
    if n < len(mini):
        return mini[n]
    x = int(n**(1./3) + 1)
    ct = bestup2(n)
    while x > 0:
        if x**3 <= n:
            bd = min((x+1)**3 - x**3, n - x**3)
            if bestup2(bd) == ct - 1:
                # print 'found', (n, x)
                return x**3 + bestbl2(bd)

        x -= 1

n = input()
print bestup2(n), bestbl2(n)