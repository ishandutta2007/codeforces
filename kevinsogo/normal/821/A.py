n = input()
grid = []
for i in xrange(n):
    row = map(int, raw_input().split())
    grid.append(row)

def good():
    for i in xrange(n):
        for j in xrange(n):
            if not goodcell(i, j):
                return False
    return True

def goodcell(I, J):
    if grid[I][J] == 1: return True
    for i in xrange(n):
        for j in xrange(n):
            if grid[I][J] == grid[I][j] + grid[i][J]:
                return True
    return False

print 'Yes' if good() else 'No'