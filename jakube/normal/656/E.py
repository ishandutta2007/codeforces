n = int(raw_input())

m = map(lambda _: map(int, raw_input().split(' ')), range(n))

m = reduce(lambda G, H: map(lambda (i, line): map(lambda (j, value): min(value, min(map(lambda t: G[i][t] + G[t][j],  range(n)))), enumerate(line)), enumerate(G)), range(n + 1), m)

print max(map(max, m))