def main():
    n = int(input())
    d = [input() for i in range(n)]
    
    figures = []
    for i in range(n):
        for j in range(n):
            if d[i][j] == 'o':
                figures.append((i, j))
    
    result = [['x' for i in range(2 * n - 1)] for j in range(2 * n - 1)]
    result[n - 1][n - 1] = 'o'
    for i in range(n):
        for j in range(n):
            if d[i][j] == '.':
                for x, y in figures:
                    dx, dy = x - i, y - j
                    result[n - 1 - dx][n - 1 - dy] = '.'
    for i in range(n):
        for j in range(n):
            if d[i][j] == 'x':
                for x, y in figures:
                    dx, dy = x - i, y - j
                    if result[n - 1 - dx][n - 1 - dy] == 'x':
                        break
                else:
                    print("NO")
                    return
    print("YES")
    for i in result:
        print(''.join(i))
                        


main()