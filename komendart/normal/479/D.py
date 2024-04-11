def main():
    import sys
    
    tokens = [int(i) for i in sys.stdin.read().split()]
    tokens.reverse()
    
    n, l, x, y = [tokens.pop() for i in range(4)]
    marks = set(tokens)
    
    flag_x = flag_y = False
    index = -1
    for i in marks:
        if i + x in marks:
            flag_x = True
            index = y
        if i + y in marks:
            flag_y = True
            index = x
        if i + x + y in marks:
            index = i + x
        if i + y - x in marks and i - x >= 0:
            index = i - x
        if i + y - x in marks and i + y <= l:
            index = i + y
    
    if flag_x and flag_y:
        print(0)
    elif index != -1:
        print(1)
        print(index)
    else:
        print(2)
        print(x, y)
    
    
main()