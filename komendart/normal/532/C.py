def main():
    def dist(x1, y1, x2, y2):
        return max(abs(x1 - x2), abs(y1 - y2))
    
    xp, yp, xv, yv = [int(i) for i in input().split()]
    
    win = -1
    while True:
        if xp == 0:
            yp -= 1
        elif yp == 0:
            xp -= 1
        elif dist(xp - 1, yp, xv, yv) < dist(xp, yp - 1, xv, yv):
            xp -= 1
        else:
            yp -= 1
        if xp == 0 and yp == 0:
            win = 0
            break
        
        if xv == 0:
            if xp == 0 and yv - yp == 1:
                win = 0
                break
            yv -= 1
        elif yv == 0:
            if yp == 0 and xv - xp == 1:
                win = 0
                break
            xv -= 1
        else:
            if yv - yp == 1 and xv - xp == 1:
                win = 0
                break
            xv -= 1
            yv -= 1
        if xv == 0 and yv == 0:
            win = 1
            break
    
    print(["Polycarp", "Vasiliy"][win])
        
    
main()