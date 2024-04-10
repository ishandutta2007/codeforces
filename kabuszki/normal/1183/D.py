from sys import stdin
input = stdin.readline

q = int(input())
d = [0] * 200005

for query in range(q):
    n = int(input())
    for i in range(n + 1):
        d[i] = 0
    for i in input().split():
        d[int(i)] += 1
    ziom = d[:(n + 1)]
    ziom.sort()
    thres = 10000000
    wyn = 0
    bla = False
    for i in reversed(range(len(ziom))):
        if thres <= 0:
            print(wyn)
            bla = True
            break
        wyn += min(thres - 1, ziom[i])
        thres = min(thres - 1, ziom[i])

    if not bla:
        print(wyn)