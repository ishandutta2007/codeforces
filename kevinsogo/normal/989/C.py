a, b, c, d = map(int, raw_input().split())
rows = cols = 50
bd = 8
grid = [['A' if i < bd else 'B']*cols for i in xrange(rows)]
a -= 1
b -= 1
for i in xrange(0, bd - 1, 2):
    for j in xrange(1, cols, 2):
        if b:
            grid[i][j] = 'B'
            b -= 1
assert b == 0
assert min(a, c, d) >= 0
letters = ['A']*a + ['C']*c + ['D']*d
for i in xrange(bd + 1, rows - 1, 2):
    for j in xrange(1, cols - 1, 2):
        if letters:
            grid[i][j] = letters.pop()

print rows, cols
print '\n'.join(map(''.join, grid))