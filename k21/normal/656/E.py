from itertools import product

def relax(D, t):
    k, i, j = t
    D[i][j] = min(D[i][j], D[i][k] + D[k][j])

N = int(input())
D = list(map(lambda i:list(map(int, input().split())), range(N)))
list(map(lambda t: relax(D, t), product(range(N), range(N), range(N))))
print(max(map(max, D)))