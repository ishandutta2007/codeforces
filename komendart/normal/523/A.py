w, h = [int(i) for i in input().split()]
bitmap = [list(input()) for i in range(h)]

bitmap = [[bitmap[i // 2][j // 2] for i in range(2 * h)] for j in range(2 * w)]

print('\n'.join(''.join(i) for i in bitmap))