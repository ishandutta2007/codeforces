def main():
    n, m = [int(i) for i in input().split()]
    table = [input() for i in range(n)]
    
    for i in range(n):
        for j in range(m):
            if table[i][j] == '-': print('-', end='')
            elif (i + j) % 2 == 0: print('B', end='')
            else: print('W', end='')
        print()

main()