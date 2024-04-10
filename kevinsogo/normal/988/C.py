total = {}
for i in range(int(input())):
    input()
    a = list(map(int, input().split()))
    s = sum(a)
    idx = {v: i for i, v in enumerate(a)}
    for v in set(a):
        p = idx[v]
        if s - v in total:
            I, P = total[s - v]
            print('YES')
            print(I + 1, P + 1)
            print(i + 1, p + 1)
            exit()
        else:
            total[s - v] = i, p
print('NO')