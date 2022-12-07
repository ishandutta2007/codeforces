import itertools
 
n = int(input())
x1, y1 = [int(a) - 1 for a in input().split()]
x2, y2 = [int(a) - 1 for a in input().split()]
board = [list(input()) for i in range(n)]

def ma_sens(x, y):
    global board
    return not (x < 0 or x >= n or y < 0 or y >= n or board[x][y] != '0')
 
def bfs(x, y, c):
    global board
    tab = [(x, y)]
    pocz = 0
    board[x][y] = c
    while pocz < len(tab):
        x, y = tab[pocz]
        pocz += 1
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            if ma_sens(x + dx, y + dy):
                board[x + dx][y + dy] = c
                tab.append((x + dx, y + dy))
    return tab

res = 13337
for a, b in itertools.product(bfs(x1, y1, 's'), bfs(x2, y2, 'e')):
    res = min(res, (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)
print(res)