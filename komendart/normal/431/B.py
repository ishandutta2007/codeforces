from itertools import permutations

g = [[int(i) for i in input().split()] for j in range(5)]
max_joy = -1
for p in permutations([0, 1, 2, 3, 4]):
    joy = (g[p[0]][p[1]] + g[p[2]][p[3]] + g[p[1]][p[0]] + g[p[3]][p[2]]) + (
           g[p[1]][p[2]] + g[p[3]][p[4]] + g[p[2]][p[1]] + g[p[4]][p[3]]) + (
           g[p[2]][p[3]] + g[p[3]][p[2]]) + (g[p[3]][p[4]] + g[p[4]][p[3]])
    if joy > max_joy:
        max_joy = joy

print(max_joy)